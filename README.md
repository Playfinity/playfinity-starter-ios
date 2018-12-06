# Playfinity

The Playfinity Team is thanking you for trying out the Playfinity SDK!

If you are new to Playfinity, check out our products at https://playfinity.io

At Playfinity, we make:

- our own game console (sensor chip) that can be put into various things
- a throwing ball (Ø 10 cm), a PU ball that you can put the game console inside
- games built on our own SDK, for iOS and Android:
-- High5 ball throwing app
-- Trix football freestyle app
-- Trampoline app where you put the game console in your pocket

Check out videos on our website to see in-action footage.

## The SDK

The Playfinity SDK lets you as developer create apps or games on the Playfinity platform (just as we have created our apps on the same SDK).

When you write your app, you define in which mode you shall use the console:

- Throwing ball
- Freestyle football
- Trampoline

You can also subscribe to raw data to receive un-touched data from the console at 50 samples per second.

## Ball events

We have worked really hard to make your job as simple as possible.

It all started with a ball you can throw. We have spent hundreds of hours recording data, analyzing them and implementing algorithms to detect events such as:

- ball throw
- ball catch
- ball bounce
- ball miss
- ball flight air-time
- ball height
- ball speed

We have also created events for trampoline:

- jump
- land on feet. We shall add land on back and land on front.
- events have attached properties such as
-- jump height
-- jump rotation in degrees

And we have created events for freestyle football:

- ball kick
- ball bounce
- ball miss
- ball flight air-time
- ball height

All of this is available for you. You can focus on the game experience.

## Discovering the console

All complexity has been hidden.

The console pairs simply by bringing it close to the phone. Maybe you need to press the button on the console to wake it, but that's it.

## Nice to know

The sample app is equipped with a "test" developer- and app-identifier.
So you can download, create and run your app on your devices.

If you change the bundle identifier, you must register at Playfinity, since the "test" identifiers is bound to the bundle identifier shipped in this sample app.

### Register if you deploy to AppStore

It means that when you want to upload to the App Store, you will need to register the app with Playfinity servers first.

When you register, you receive your own "APP_ID" and "DEV_ID".

Since we do not yet have a Developer Portal, you must register manually by writing to us at labs@playfinity.io

Provide the following information:
- Name
- Address
- Contact phone
- Contact e-mail
- App name
- App bundle identifier

### Internet and offline functionality

The framework needs Internet to validate with Playfinity servers.

After a validation, it will work offline for one week until new validation is required.

The same is for pairing a console. First time pairing requires Internet for validating the console, and thereafter you can be offline for one week before next validation is required.
