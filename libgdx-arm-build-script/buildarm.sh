git fetch
git pull
cd gdx/jni/
ant -f build-linuxarm.xml
cd ../../extensions/gdx-box2d/gdx-box2d/jni/
ant -f build-linuxarm.xml
cd ../../../gdx-bullet/jni/
ant -f build-linuxarm.xml
cd ../../gdx-controllers/gdx-controllers-desktop/jni/
ant -f build-linuxarm.xml
cd ../../../gdx-freetype/jni/
ant -f build-linuxarm.xml
cd ../../../
