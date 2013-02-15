Miles Spotify Support
=====================

This prototype was to demonstrate the use of [Hallon](https://github.com/Burgestrand/Hallon) and [Hallon-openal](https://github.com/Burgestrand/hallon-openal) to stream music from Spotify.


Setup
-----

1. Copy your [spotify_appkey.key](https://developer.spotify.com/technologies/libspotify/keys/) file to this directory
2. `export SPOTIFY_USERNAME='username'`
3. `export SPOTIFY_PASSWORD='password'`
4. `bundle install`
5. `bundle exec ruby search_and_play.rb 'Thrift Shop'`
6. Pop Tags


How it works
------------------

The script searches Spotify for the top 10 tracks matching your search and then, unless specified otherwise, plays the first match. A second argument can be provided to specify which of the tracks you wish to play…


```
➜  spotify git:(master) ✗ bundle exec ruby search_and_play.rb 'thrift shop'  
Logging in to Spotify...
Logged in to Spotify

Searching for 'thrift shop'...
Top 10 results for "thrift shop": 
[1] Thrift Shop - feat. Wanz - Macklemore & Ryan Lewis (spotify:track:1CmUZGtH29Kx36C1Hleqlz)
[2] Thrift Shop - feat. Wanz - Macklemore & Ryan Lewis (spotify:track:37rKwjBHaZurlyPYy3Nqvz)
[3] Thrift Shop - Thrift Shop (spotify:track:2SiIfYLt6xr5gVF5crBOnq)
[4] Thrift Shop - feat. Wanz - Macklemore & Ryan Lewis (spotify:track:4YMqbFcDIFiCBd02PzUBcM)
[5] Thrift Shop (Super Clean Radio Mix) - Mama's Soap Shop (spotify:track:18FLjY5QEm4iaVFLzyYwqb)
[6] Thrift Shop (originally by Macklemore) - Alex G (spotify:track:5N790g9r2exNLATjCto9X7)
[7] Thrift Shop (originally by Macklemore) - Tyler Ward & Lindsey Stirling (spotify:track:0EYKD5N0mldDeVTCzCfzqr)
[8] Thrift Shop - Thrift Shop (spotify:track:1slVI5tfyMTaNn3BRsIyj4)
[9] Thrift Shop (Clean Remix) - Groove Shop (spotify:track:25ntvxjsygfM9NVeKr6jch)
[10] I'm Gonna Pop Some Tags (Thrift Shop) - Top 40 Hip-Hop Hits (spotify:track:0JTr1u69EAcPuCGI1MFyHt)

Now playing Thrift Shop - feat. Wanz by Macklemore & Ryan Lewis



➜  spotify git:(master) ✗ bundle exec ruby search_and_play.rb 'thrift shop' 6
Logging in to Spotify...
Logged in to Spotify

Searching for 'thrift shop'...
Top 10 results for "thrift shop": 
[1] Thrift Shop - feat. Wanz - Macklemore & Ryan Lewis (spotify:track:1CmUZGtH29Kx36C1Hleqlz)
[2] Thrift Shop - feat. Wanz - Macklemore & Ryan Lewis (spotify:track:37rKwjBHaZurlyPYy3Nqvz)
[3] Thrift Shop - Thrift Shop (spotify:track:2SiIfYLt6xr5gVF5crBOnq)
[4] Thrift Shop - feat. Wanz - Macklemore & Ryan Lewis (spotify:track:4YMqbFcDIFiCBd02PzUBcM)
[5] Thrift Shop (Super Clean Radio Mix) - Mama's Soap Shop (spotify:track:18FLjY5QEm4iaVFLzyYwqb)
[6] Thrift Shop (originally by Macklemore) - Alex G (spotify:track:5N790g9r2exNLATjCto9X7)
[7] Thrift Shop (originally by Macklemore) - Tyler Ward & Lindsey Stirling (spotify:track:0EYKD5N0mldDeVTCzCfzqr)
[8] Thrift Shop - Thrift Shop (spotify:track:1slVI5tfyMTaNn3BRsIyj4)
[9] Thrift Shop (Clean Remix) - Groove Shop (spotify:track:25ntvxjsygfM9NVeKr6jch)
[10] I'm Gonna Pop Some Tags (Thrift Shop) - Top 40 Hip-Hop Hits (spotify:track:0JTr1u69EAcPuCGI1MFyHt)

Now playing Thrift Shop (originally by Macklemore) by Alex G
```