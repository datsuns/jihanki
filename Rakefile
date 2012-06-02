require 'rake/clean'

CC = "g++"

task :default => "jihanki"


SRCS = FileList["**/*.cpp"]
OBJS = SRCS.ext('o')

OPTION = '-L./lib -lgtest -lgtest_main'

file "jihanki" => OBJS do |t|
	  sh "#{CC} #{OPTION} -o #{t.name} #{t.prerequisites.join(' ')}" 
end

rule '.o' => '.cpp' do |t|
	  sh "#{CC} -I./inc -c #{t.source}"
end

task "run" do
	  sh "./jihanki"
end

CLEAN.include(OBJS)
CLOBBER.include("jihanki")

