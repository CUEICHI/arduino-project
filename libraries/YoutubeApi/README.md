# arduino-youtube-api
A wrapper for the [YouTube API](https://developers.google.com/youtube/v3/docs/) for Arduino (works on ESP8266)

Currently the only implemented method is getting the channel statistics but it can be easily extended. Please raise an issue if there is a method you are looking for.

![Imgur](http://i.imgur.com/FmXyW4E.png)

### Support what I do!

I have created a lot of different Arduino libraries that I hope people can make use of. [If you enjoy my work, please consider becoming a Github sponsor!](https://github.com/sponsors/witnessmenow/)

## Getting a Google Apps API key (Required!)

* Create an application [here](https://console.developers.google.com)
* On the API Manager section, go to "Credentials" and create a new API key
* Enable your application to communicate the YouTube Api [here](https://console.developers.google.com/apis/api/youtube)
* Make sure the following URL works for you in your browser (Change the key at the end!):
https://www.googleapis.com/youtube/v3/channels?part=statistics&id=UCezJOfu7OtqGzd5xrP3q6WA&key=PutYourNewlyGeneratedKeyHere

## Installing

The easiest way to install this library is through the aduino library manager, just search for "Youtube"

You also have to install the ArduinoJson library written by [Benoît Blanchon](https://github.com/bblanchon). Search for it on the Arduino Library manager or get it from [here](https://github.com/bblanchon/ArduinoJson).

Include YoutubeApi in your project:

    #include <YoutubeApi.h>

and pass it a Bot token and a SSL Client (See the examples for more details)

    #define API_KEY "XXXXXXXXX:XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
    // WiFiSSLClient client; //For 101 boards
    WiFiClientSecure client; //For ESP8266 boards
    YoutubeApi bot(API_KEY, client);

*NOTE:* This library has not been tested with the 101 boards as I do not have a compatible board. If you can help please let me know!
