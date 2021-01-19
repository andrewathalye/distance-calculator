Distance Calculator

This repository includes tools for use with LocationLogger that will help you to better process its data
and determine player proximity to various coordinates.

Included Tools:
distance.c -> distance
	Usage: ./distance X Y Z < pos.txt > dist.txt
	This tool allows you to calculate the distance of any number of space-separated coordinates from a given 3D location.
process.c -> process
	Usage: ./process data.txt dist.txt sort.txt NUM > results.txt
	This tool takes various data and outputs a list of players, their distance from your destination, and the time at which they were there.
logincords.sh
	Usage: ./logincords.sh logins.txt > pos.txt
	Takes the portion of a log file containing only login lines and extracts login coordinates, space-separated.

Instructions for LocationLogger:
	Extract a log from your chosen day, then grep overworld/the_nether/the_end FILE > data.txt
	This extracts only position data from the same dimension, which is very useful.
	cut -d' ' -f3-5 data.txt | ./distance X Y Z > dist.txt, in order to produce a distance file
	sort -g dist.txt > sort.txt, in order to sort them by least distance to greatest distance
	Finally, ./process data.txt dist.txt sort.txt NUM > results.txt

These tools can also generally be used with any other utility that logs location data for Minecraft (or any other 3D situation really)
See the LocationLogger repository for the intended format of data.txt

