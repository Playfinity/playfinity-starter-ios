# Playfinity SDK iOS Sample 

This sample application is here to help customers get up and running with Playfinity SDK on iOS.

The Playfinity SDK communicates with playOS on the Playfinity console.

-------

<p align="center">
    <a href="https://playfinity.io/">Playfinity.io</a>
    :heavy_check_mark:
    <a href="https://www.facebook.com/playfinity.io/">Facebook</a>
    :heavy_check_mark:
    <a href="https://www.instagram.com/playfinity_io/">Instagram</a>
    :heavy_check_mark:
    <a href="https://www.youtube.com/channel/UCiJSGEIcw_-OHlYjTOeJ-Ag/featured/">Youtube</a>
</p>

-------

### What's included :rocket:
- PlayfinityKit SDK FAT(x86 and arm) and release(arm)
- PlayfinityKit console discovering and pairing (BLE)
- Listening and reacting to console events
- Sounds
- Ball throwing sample
- Trampoline jumping sample
- Trick ball sample
- Cloud transporter
- Coded in Swift

# Preview

## Screenshots 

![Image](https://github.com/Playfinity/playfinity-starter-ios/blob/public/screenshot.PNG?raw=true)

Sample app screenshot with successfully connected SDK and Playfinity Console (real device photo)

# How to use

## Requirements 

PlayfinityKit targets iOS 11 and newer.

## Setup

`Info.plist`

```xml
<key>CLOUD_API_URL</key>
<string>https: //cloud.playfinity.io/</string>
```

Drag and drop `PlayfinityKit.framework` into your project. 
There are `universal/PlayfinityKit.framework` that contains symbols required by iOS simulator
There are `release/PlayfinityKit.framework`  use this one for Appstore uploads. 

## Console mode

Playfinity Console can operate in a several different modes. For example it can act like a ball or a trampoline ankle band.<br>
While initialising Playfinity SDK we can choose what mode to use:

```swift
let config = Configuration.init(applicationKey: "SAMPLE_TEST", developerId: "SAMPLE_TEST", sensorType: SensorType.ball)
PlayfinityKit.validate(configuration: config) { [weak self] (result) in
    guard  let  self = self  else { return }
    switch result {
        case .success(let sdk):
            ()
        case .failure(let error):
            ()
        }
}
```
After config validation you are able to add 
```swift
public  protocol  SensorObserver : AnyObject {
    func playfinityKit(_ playfinityKit: PlayfinityKit.PlayfinityKit, didFoundSensor sensor: PlayfinityKit.Sensor)
    func playfinityKit(_ playfinityKit: PlayfinityKit.PlayfinityKit, lowBatteryOn sensor: PlayfinityKit.Sensor)
    func playfinityKit(_ playfinityKit: PlayfinityKit.PlayfinityKit, didGetEvent event: PlayfinityKit.BallEvent, onSensor sensor: PlayfinityKit.Sensor)
    func playfinityKit(_ playfinityKit: PlayfinityKit.PlayfinityKit, didGetEvent event: PlayfinityKit.TrampolineEvent, onSensor sensor: PlayfinityKit.Sensor)
    func playfinityKit(_ playfinityKit: PlayfinityKit.PlayfinityKit, didGetEvent event: PlayfinityKit.FootballEvent, onSensor sensor: PlayfinityKit.Sensor)
}
```

After config validation you are able to use `public  func  addObserver(_ observer: PlayfinityKit.SensorObserver)`
from:
```swift
public  class  PlayfinityKit {
    public static func validate(configuration: PlayfinityKit.Configuration, completion: @escaping (Result<PlayfinityKit.PlayfinityKit, Error>) -> ())
    public  func  scan()
    public  func  stopScan()
    public  func  addObserver(_ observer: PlayfinityKit.SensorObserver)
    public  func  removeObserver(_ observer: PlayfinityKit.SensorObserver)
}
```

## Available Sensor Types

### 1. `ball`
Will Produce:
```swift
public  enum  BallEvent {
//speed in km/h
case throwEvent(speed: Double)
//airTime in milis, height in cm
case catchEvent(airTime: Double, height: Double)
//airTime in milis, height in cm
case missEvent(airTime: Double, height: Double)
//airTime in milis, height in cm
case bounceEvent(airTime: Double, height: Double)
case  buttonPressEvent
}
```

### 2. `trampoline`

Will Produce:
```swift
public enum TrampolineEvent {
    case jumpEvent
    //yawRotation and pitchRotation in degrees
    case landFeetEvent(yawRotation: Double, pitchRotation: Double)
    case buttonPressEvent
}
```

### 3. `football`
Will Produce:
```swift
public enum FootballEvent {
    //speed in km/h
    case kickEvent(speed: Double)
    case missEvent
    case bounceEvent
    case buttonPressEvent
}
```

## Cloud Transponder :cloud:
Playfinity Cloud Transponder enables an option to send console events to a specified endpoint in real time.<br>
To toggle it, you need to add `Settings.bundle` to your project.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>StringsTable</key>
    <string>Root</string>
    <key>PreferenceSpecifiers</key>
    <array>
        <dict>
            <key>Type</key>
            <string>PSToggleSwitchSpecifier</string>
            <key>Title</key>
            <string>playfinity_cloud</string>
            <key>Key</key>
            <string>cloud_enabled</string>
            <key>DefaultValue</key>
            <false/>
        </dict>
    </array>
</dict>
</plist>
```

Or change it calling directly `UserDefaults.standard.set(true, forKey: "cloud_enabled")`

To change endpoint url replace in `Info.plist`

```xml
<key>CLOUD_API_URL</key>
<string>https://cloud.playfinity.io/</string>
```

with your own URL.

Request sent by app will look like:

`curl -H 'Host: X' -H 'appId: SAMPLE_TEST' -H 'Accept: */*' -H 'playerId: SAMPLE_TEST' -H 'appVersion: 1.0.0' -H 'Accept-Language: pl-pl' -H 'platform: iOS' -H 'Cache-Control: no-cache' -H 'User-Agent: PlayfinityKitExample/1 CFNetwork/1121.2.2 Darwin/19.3.0' -H 'phoneId: X' -H 'Content-Type: application/json; charset=utf-8' --data-binary '{"events":[{"event":"buttonTop","airtime":0,"speed":0,"height":0,"at":"2020-04-15T08:34:52.395Z","from":"-","key":"buttonTop_1_127","flip":0,"by":"D4FF202E36D5@151BD5E69094","md5":"1191f1ca51b103ce41072309f9266533","rotation":0,"action":127}]}' --compressed 'CLOUD_API_URL/event'`

where `event` can be:

`buttonTop, thrown, caught, landFeet, jump, bounce, miss`


# License

    Copyright 2020 Playfinity.io

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
