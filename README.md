# QTweetGettr

Get tweets with Qt in C++ Demo, for Mac desktop, iOS and Android.

A port of [SwiftTweetGettr](https://github.com/sarah-j-smith/SwiftTweetGettr) which is a little learning demo in Swift.

Might run on other plaforms as well, but I haven't tried.  The instructions below are for Mac OS Sierra.

# Dependencies

* Xcode 
* [Qt 5.x](https://www1.qt.io/download-open-source/)

> Note: read the section on the LGPL on the above link carefully.  This project is completely
> open source so uses the Open Source version.  Use the right version for your project, and
> if trialling Qt it for a commercial project get the free trial version.

On install make sure to get the following Qt kits (open up the optional leaves on the
installer) which enable mobile compiles:

    * iOS
    * MacOS
    * Android

* [Android command line tools](https://developer.android.com/studio/index.html#downloads)

Android Studio is a big download and takes a lot of space. I just use the command line tools
to save on space. I used [tools_r25.2.5-macosx.zip](http://dl.google.com/android/repository/tools_r25.2.5-macosx.zip).

Note that Qt Creator detects the Android toolchains and parses its outputs, and may not handle the latest SDK's so use Stable or earlier SDK's if problems are seen.
In particular Android tools 26.x caused problems for me, with Qt Creator 5.9.1, so I stuck to 25.x.

After downloading unzip (if needed) and move the `tools` folder to a new folder:

    mkdir -p ~/android
    mv ~/Downloads/tools ~/android/.

    # If Java is not installed this will prompt to install on Mac
    ~/android/tools/bin/sdkmanager --help

    # Suppress warnings about config
    touch $HOME/.android/repositories.cfg

* If needed install [Java 8 SDK](http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html)
    * Note: `sdkmanager` crashed with Java exceptions using JDK 9, so I used JDK 8.

* Determine the API Level for the devices being targetted
    * I'm using an old Nexus 7 tablet, looking at System > About tablet I see its running Lollipop (5.1)
    * Checking the [Android documentation](https://source.android.com/source/build-numbers) shows I need API 22 & NDK 8
    * Get a full list of all Android dev packages and find the ones needed
        * `~/android/tools/bin/sdkmanager --list --verbose"`
    * Platform tools - I'm using 25
        * `~/android/tools/bin/sdkmanager "platforms;android-25"`
    * Build tools
        * `~/android/tools/bin/sdkmanager "ndk-bundle"`
            * This one is huge, and the command will take a *long* time to finish :-(
        * `~/android/tools/bin/sdkmanager "lldb;2.3"`
        * `~/android/tools/bin/sdkmanager "cmake;3.6.4111459"`
        * `~/android/tools/bin/sdkmanager "build-tools;22.0.1"`
    * If using the emulator
        * `~/android/tools/bin/sdkmanager "system-images;android-22;google_apis;x86_64"`
        * `~/android/tools/bin/sdkmanager "extras;intel;Hardware_Accelerated_Execution_Manager"`
        * `~/android/tools/bin/sdkmanager "emulator"`

