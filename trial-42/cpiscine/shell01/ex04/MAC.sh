#!/bin/sh

ifconfig | grep eth | cut -c 8-24
