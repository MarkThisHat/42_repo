#!bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 15:22:36 by maalexan          #+#    #+#              #
#    Updated: 2023/01/05 20:45:09 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

arch=$(uname -a)
cpup=$(nproc --all) # alt: $(lscpu | grep "CPU(s):" | tr -d -c 0-9 OR sed 's/[^0-9]//g')
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
tmem=$(free -m | grep Mem | awk '{print $2}')
umem=$(free -m | grep Mem | awk '{print $3}')
pmem=$(free -m | grep Mem | awk '{printf("%.2f"), $3/$2*100}')
dspc=$(df -Bm --output=source,size,used | grep /dev | awk '{sum += $2} END {print sum/1000}') # space in MB  (/1000 to get Gb)
uspc=$(df -Bm --output=source,size,used | grep /dev | awk '{sum += $3} END {print sum/1000}') # space in MB
pspc=$(df -Bm --output=source,size,used | grep /dev | awk '{d += $3} {u += $2} END {printf("%.2f"), d/u*100}')
cplo=$(top -bn1 | grep load | awk '{print $11}') #can use sudo apt-get install sysstat and (mpstat | grep all | awk '{print 100-$13}')
rebo=$(who -b | awk '{print $3" "$4}')
lvmb=$(lsblk | grep lvm | wc -l)
lvmu=$(if [ $lvmb -ge 1 ]; then echo yes; else echo no; fi)
tcpc=$(netstat -ant | grep ESTABLISHED | wc -l) #add another rule
usrs=$(users | wc -l)
dbip=$(hostname -I)
maca=$(ip addr | grep ether | head -1 | awk '{print $2}')
suco=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)
wall "  #Architecture: $arch
	    #CPU physical: $cpup
	    #vCPU: $vcpu
	    #Memory Usage: $umem/${tmem}MB ($pmem%)
	    #Disk Usage: $uspc/${dspc}Gb ($pspc%)
	    #CPU load: $cplo
	    #Last boot: $rebo
	    #LVM use: $lvmu
	    #Connections TCP: $tcpc ESTABLISHED
	    #User log: $usrs
	    #Network: IP $dbip ($maca)
	    #Sudo: $suco cmd"