Pod::Spec.new do |s|
  s.name         = "protonet"
  s.version      = "0.0.1"
  s.summary      = "Protocol Buffers - Network Implementation."
  s.homepage     = "https://github.com/axet/protonet"
  s.license      = { :type => 'LGPL3.0', :file => 'lgpl-3.0.txt' }
	s.author       = { "Alexey Kuznetsov" => "axet@me.com" } 
  s.source       = { :git => "https://github.com/axet/protonet.git", :commit => "34422f9c664e78c2d5ce67d8a3b01081d34de53d" }
  s.platform     = :ios, '5.0'
  s.public_header_files = 'protonet-objc/**/*.h'
  s.source_files = 'protonet-objc/**/*.{h,mm}'
	
	s.dependencies = { 'protobuf' => '~> 2.0.5', 'CocoaAsyncSocket' => '~> 7.3.1' }
end
