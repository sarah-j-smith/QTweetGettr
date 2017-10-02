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

* If needed install [Java 8 SDK](http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html)
    * Note: `sdkmanager` crashed with Java exceptions using JDK 9, so I used JDK 8.

* [Android command line tools](https://developer.android.com/studio/index.html#downloads)

Android Studio is a big download and takes a lot of space. I just use the command line tools
to save on space. I used [tools_r25.2.5-macosx.zip](http://dl.google.com/android/repository/tools_r25.2.5-macosx.zip).

Note that Qt Creator detects the Android toolchains and parses its outputs, and may not handle the latest SDK's so use Stable or earlier SDK's if problems are seen.
In particular Android tools 26.x caused problems for me, with Qt Creator 5.9.1, so I stuck to 25.x.

After downloading unzip (if needed) and move the `tools` folder to a new folder:

    mkdir -p ~/android
    mv ~/Downloads/tools ~/android/.

    // Run the SDK manager
    ~/android/tools/android

* Determine the API Level for the devices being targetted
    * I'm using an old Samsung Nexus phone, looking at System > About I see its running 4.3
    * Checking the [Android documentation](https://source.android.com/source/build-numbers) shows I need API 18
    * Install the following:
        * Tools
            * Android SDK Tools
            * Android SDK Built Tools
        * API platform
            * SDK Platform (in my case 4.3.1 (18)
        * Extras
            * ndk-bundle
    * If you want to use the emulator:
        * Emulator
        * HAXM & system image


