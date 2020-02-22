# 1) go to appropriate path
cd ../build/install/WebsiteCracker/lib

# 2) generate information for reflection 
java -agentlib:native-image-agent=config-output-dir=META-INF/native-image -cp commons-codec-1.10.jar:commons-logging-1.2.jar:httpclient-4.5.6.jar:httpcore-4.4.10.jar:WebsiteCracker.jar  io.github.fxzjshm.websitecracker.Case7

# 3) generate the native image
native-image --enable-http --enable-https -cp commons-codec-1.10.jar:commons-logging-1.2.jar:httpclient-4.5.6.jar:httpcore-4.4.10.jar:WebsiteCracker.jar:. io.github.fxzjshm.websitecracker.Case7 --verbose --no-fallback
