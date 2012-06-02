require 'rake/clean'

CC = "g++-mp-4.7 -std=c++11"

task :default => "jihanki"

SRCS = FileList["**/*.cpp"]
OBJS = SRCS.ext('o')

OPTION = '-L./lib -lgtest -lgtest_main'

file "jihanki" => OBJS do |t|
	  sh "rm ./jihanki"
	  sh "#{CC} #{OPTION} -o #{t.name} #{t.prerequisites.join(' ')}" 
	  sh "./jihanki"
end

rule '.o' => '.cpp' do |t|
	  sh "#{CC} -I./inc -c #{t.source}"
end

task "run" do
	  sh "./jihanki"
end

CLEAN.include(OBJS)
CLOBBER.include("jihanki")

