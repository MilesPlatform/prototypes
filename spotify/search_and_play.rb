require 'hallon'
require 'hallon/openal'

query_input = ARGV[0]
track_number = (ARGV[1] || 1).to_i - 1

spotify_username = ENV['SPOTIFY_USERNAME']
abort("Please specify username with \"export SPOTIFY_USERNAME='USERNAME'\"") unless spotify_username

spotify_password = ENV['SPOTIFY_PASSWORD']
abort("Please specify password with \"export SPOTIFY_PASSWORD='USERNAME'\"") unless spotify_username

puts "Logging in to Spotify..."
session = Hallon::Session.initialize IO.read('./spotify_appkey.key')
session.login!(spotify_username, spotify_password)
puts "Logged in to Spotify"

player = Hallon::Player.new(Hallon::OpenAL)

puts "\nSearching for '#{query_input}'..."
search = Hallon::Search.new(query_input)
search.load

tracks = search.tracks[0...10].map(&:load)

abort("No tracks found for \"#{query_input}\"") unless tracks.length > 0

puts "Top 10 results for \"#{search.query}\": "
tracks.each_with_index do |track, index|
	puts "\[#{index + 1}\] #{track.name} - #{track.artist.name} (#{track.to_link.to_str})"
end

track = tracks[track_number]

artist = track.artist.load
puts "\nNow playing #{track.name} by #{artist.name}"

player.play!(track)