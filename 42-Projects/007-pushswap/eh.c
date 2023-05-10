#include <stdio.h>

int	optimal_partitioning(int size)
{
	if (size < 101)
		return (5);
	else
		return (11);
}
/*
int	find_chunk(int size, int pivot)
{
	static int	i;

	if (pivot == size)
		i = optimal_partitioning(size);
	i--;
	return ((size * i) / optimal_partitioning(size));
}
*/

int	find_chunk(int size, int pivot)
{
	static int	i;

	i++;
	if (i < optimal_partitioning(size))
		return ((size * i) / optimal_partitioning(size));
	else
		return (0);
}

int main(int argc, char **argv)
{
	int	pivot;
    int size = 500;
	
//	printf("ARGC: %i\n",argc);
	(void)argv;
	pivot = size;
	while (pivot)
		if (pivot)
        	printf("%i\n", pivot = find_chunk(size, pivot));
}

/*

int	main(void)
{
	int n;
    int i;

	n = 103;
    i = 5;
    while (--i)
	    printf("%i\n", (n * i) / 5);
}

*/


/*

io.vertx.core.VertxException: Thread blocked
    at io.vertx.core.net.impl.TCPServerBase.listen(TCPServerBase.java:125)
    at io.vertx.core.net.impl.TCPServerBase.bind(TCPServerBase.java:100)
    at io.vertx.core.http.impl.HttpServerImpl.listen(HttpServerImpl.java:217)
    at io.vertx.core.http.impl.HttpServerImpl.listen(HttpServerImpl.java:149)
    at io.vertx.core.http.impl.HttpServerImpl.listen(HttpServerImpl.java:154)
    at io.quarkus.vertx.http.runtime.VertxHttpRecorder$WebDeploymentVerticle.setupTcpHttpServer(VertxHttpRecorder.java:1242)
    at io.quarkus.vertx.http.runtime.VertxHttpRecorder$WebDeploymentVerticle.start(VertxHttpRecorder.java:1171)
    at io.vertx.core.impl.DeploymentManager.lambda$doDeploy$5(DeploymentManager.java:196)
    at io.vertx.core.impl.DeploymentManager$$Lambda$766/0x00000008407a4040.handle(Unknown Source)
    at io.vertx.core.impl.ContextInternal.dispatch(ContextInternal.java:264)
    at io.vertx.core.impl.ContextInternal.dispatch(ContextInternal.java:246)
    at io.vertx.core.impl.EventLoopContext.lambda$runOnContext$0(EventLoopContext.java:43)
    at io.vertx.core.impl.EventLoopContext$$Lambda$767/0x00000008407a3c40.run(Unknown Source)
    at io.netty.util.concurrent.AbstractEventExecutor.runTask(AbstractEventExecutor.java:174)
    at io.netty.util.concurrent.AbstractEventExecutor.safeExecute(AbstractEventExecutor.java:167)
    at io.netty.util.concurrent.SingleThreadEventExecutor.runAllTasks(SingleThreadEventExecutor.java:470)
    at io.netty.channel.nio.NioEventLoop.run(NioEventLoop.java:503)
    at io.netty.util.concurrent.SingleThreadEventExecutor$4.run(SingleThreadEventExecutor.java:997)
    at io.netty.util.internal.ThreadExecutorMap$2.run(ThreadExecutorMap.java:74)
    at io.netty.util.concurrent.FastThreadLocalRunnable.run(FastThreadLocalRunnable.java:30)
    at java.base@11.0.11/java.lang.Thread.run(Thread.java:829)

*/