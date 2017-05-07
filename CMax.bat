@echo ON

@echo CMax is starting - cleaning
@del /Q .\out\*

@echo Stage 1. building
@python CMax.py 1>.\log\log.txt 2>.\log\err.txt

@echo Stage 2. Uploading
@adb remount
@adb push out /system/vendor/lib
adb push busybox /system/bin
adb shell chmod 777 /system/bin/busybox
adb shell stop media
adb shell busybox killall -9 mm-qcamera-daemon
adb shell start media
adb shell "ps | grep camera"
adb shell "getprop | grep camera.chromatix.versions"

@echo Completed.
@echo ON
pause