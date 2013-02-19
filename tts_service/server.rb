require 'sinatra' 
require 'espeak-ruby'
require 'digest/sha1'
require 'json'

include ESpeak

post '/tts' do
 filename = "/tmp/#{Digest::SHA1.hexdigest(params.to_s)}.mp3"
 raw = request.body.string
 input_text = ""
 begin
 	inputJSON = JSON.parse(raw)
 	input_text = inputJSON['text']
 	if input_text.empty?
 		status 400
 		return
 	end
 rescue
 	status 400
 	return
 end

 begin
 	espeak(filename, :text => input_text, :voice => 'en-uk', :speed => 145, :pitch => 45)
 	[200, {'Content-type' => 'audio/mpeg'}, File.read(filename)]
 rescue
 	status 500
 	return
 end
end