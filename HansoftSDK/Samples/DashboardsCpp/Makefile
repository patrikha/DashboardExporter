CC	= g++
CFLAGS	= -g
LDFLAGS	= -pthread -ldl

all: HansoftSDKSample_DashboardsCpp
	cp ../../Linux2.6/HPMSdk.x64.so . 

HansoftSDKSample_DashboardsCpp: HPMSdkCpp.o HansoftSDKSample_DashboardsCpp.o
	$(CC) -o $@ $^ $(LDFLAGS)

HPMSdkCpp.o: ../../HPMSdkCpp.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

HansoftSDKSample_DashboardsCpp.o: HansoftSDKSample_DashboardsCpp.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f HansoftSDKSample_DashboardsCpp HansoftSDKSample_DashboardsCpp.o HPMSdkCpp.o
