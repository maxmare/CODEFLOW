# ../code/codeflow.cpp
import fnmatch
import glob
import os
import pprint
import re# regex
import subprocess
import sys
import time



Default_types = [
	'struct', 'union', 'class', 'void',
	'#define', 'typedef',
	'char',
	'int', 'float', 'double', 'char',
	'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64',
	'real32'
]

def splittokens(str):
	buffer = ''
	tokens = []
	for ch in str:
		#print ch
		if buffer == '':
			if ch.isalpha() or ch.isdigit() or ch=='_':
				buffer += ch
			elif not ch.isspace():
				tokens.append(ch)
				continue
		else:
			if buffer[0].isdigit():
				if ch.isdigit():
					buffer += ch
					continue
				else:
					tokens.append(buffer); buffer = ''
			elif buffer[0].isalpha() or buffer[0]=='_':
				if ch.isalpha() or ch.isdigit() or ch=='_':
					buffer += ch
					continue
				else:
					tokens.append(buffer); buffer = ''
			if not ch.isspace():
				tokens.append(ch)
	if buffer != '':
		tokens.append(buffer)
	return tokens

str = ";\n\nvoid createDivPanel(screenLayout* scr, int ind, real32 perc, bool vert)"
str = "}\n\ninternal void\nGameOutputSound(game_state *GameState, game_sound_output_buffer *SoundBuffer, int ToneHz)"
str = ";\n\ntypedef int8_t int8"
pprint.pprint( splittokens(str) )

assert(not False)

def readLogic(logicbit, parent):
	print Default_types

#readLogic(1,1)
#input()
	
User_types = []# the custom types the proc discovers will be added here,
Types = list(set( Default_types + User_types ) )
codeTypes = []
result = []# entries as [ var_name, child_name, cb-link ]

arguments = sys.argv
if (len(sys.argv)!=1):
	print '#USAGE: python type_tags'
	print '#DESCRIPTION: gathers all types defined in a code base'
else :
	start_time = time.time()
	codefolder = '''Z:\code'''
	if(os.access(codefolder, os.F_OK)):
		dirlist = os.listdir(codefolder)
		print dirlist
		ft = 0;# foldertime
		count = 0

		#dirlist = ["_temp.cpp"]
		for dir in dirlist:
			sourceFile = os.path.join(codefolder, dir)
			imt = os.stat( os.path.join(codefolder, dir) )[8]# st_mtime
			with open (sourceFile, "r") as file:
				lines = file.readlines()
			for str in dirlist:
				for line in lines:
					if (line.find(str) != -1) and (line.find("#include") != -1):
						print dir, '->', str

		assert(0)

		dirlist = ["_temp.cpp"]
		for dir in dirlist:
		
			sourceFile = os.path.join(codefolder, dir)
			imt = os.stat( os.path.join(codefolder, dir) )[8]# st_mtime

			with open (sourceFile, "r") as file:
				fileString = file.read()
			# gather all // /* and */ in a map with their position, process them in order and apply the logic sequentially to blank the comments
			pos = 0
			markList = []
			while pos < (len(fileString)-1):
				nextMark = []
				str = fileString[pos:].find("//")
				if str != -1:
					nextMark.append( str )
				str = fileString[pos:].find("/*")
				if str != -1:
					nextMark.append( str )
				str = fileString[pos:].find("*/")
				if str != -1:
					nextMark.append( str )
				if len(nextMark) == 0:
					break
				span = min(nextMark)
				markList.append( span + pos)
				pos += 2 + span
			pprint.pprint(markList)				

			# now blanking the comments,
			pos = 0
			processing_comment = False
			for mark in markList:
				if fileString[mark:mark+2] == '//' and processing_comment == False:
					span = fileString[mark:].find('\n')
					endOfLine = span + mark
					fileString = fileString[:mark] + " "*span + fileString[endOfLine:]
					pos = endOfLine
				if fileString[mark:mark+2] == '/*' and mark >= pos and not processing_comment:
					processing_comment = True
					pos = mark# what about multiple open comment marks?
					print "open comment at: ", pos
				if fileString[mark:mark+2] == '*/' and processing_comment:
					endOfComment = mark+2
					print "open comment at: ", endOfComment
					span = mark+2 - pos
					count = fileString[pos:endOfComment].count("\n")
					fileString = fileString[:pos] + " "*(span-count) + "\n"*count + fileString[endOfComment:]
					pos = mark+2
					processing_comment = False

	# index all "\n"(newlines) so using both indices we can track down the position in the code
	# where a type has been defined,
	lineArray = [ fileString.find('\n') ]
	#print fileString
	print len(lineArray)
	while True:
		offset = lineArray[-1] + 1
		next_pos = fileString[offset:].find('\n')
		if next_pos == -1:
			break
		lineArray.append( next_pos + offset )
	print "no. lines: ", len(lineArray)

	# new approach, index all characters "{};" as between them there are discrete pieces of logic,
	copyString = fileString
	pos = -1
	newpos = -1
	for i in range(10):
	#while True:
		pos = copyString[newpos+1:].find("#define")
		if pos == -1:
			break
		newpos += pos + 1
		#print pos, newpos
		copyString = copyString[:newpos] + copyString[newpos:].replace("\n", ";", 1)
	
	#input("we have tokenized the #define statements")
	outString = copyString
	
	copyString = copyString.replace('{', '@')
	copyString = copyString.replace('}', '@')
	copyString = copyString.replace(';', '@')
	logicArray = [0]
	#logicArray = [ copyString.find('@') ]
	#print "logicArray: ", logicArray[-1]
	while True:
		offset = logicArray[-1] + 1
		next_pos = copyString[offset:].find('@')
		if next_pos == -1:
			break
		logicArray.append( next_pos + offset )
	#print "no. {}; characters: ", len(logicArray)
	#print "first character: ", fileString[logicArray[0]]
	#print "last character: ", fileString[logicArray[-1]]
	#print "logicArray: ", logicArray, '\n'
	
	# process between logic separator indices to extract types,
	# parenthesis are processed only if we find a function call,
	logicbit = ''
	for i, item in enumerate( logicArray[:-1] ):
		logicbit = fileString[ item : logicArray[i+1] ]
		result.append(logicbit)
		# to find out the line where the logic bit operates, look at the index of the logicbit and find the pos in the fileString
		#result.append(logicbit.replace('\n','').replace('\t','').replace(';',''))
	#pprint.pprint( result )

	#logicbit = '''#define internal static '''
	#print 'logicbit: "', logicbit, "\""
	#result = ['#define internal static']
	#result = ["void createDivPanel(screenLayout* scr, int ind, real32 perc, bool vert)"]
	
	for logicbit in result:
		#print logicbit
		wordList = splittokens(logicbit)
		#print wordList
		nextLogic = False
		for i, word in enumerate(wordList):
			#pprint.pprint( wordList )
			word = word.strip()
			for type in Types:
				#if type == word and i+1 <= len(wordList)-1:
				if type == word:
					if word == '#define':
						codeTypes.append(wordList[i+1])
						#print wordList[i+1]
						nextLogic = True
					elif word == 'typedef':
						codeTypes.append(wordList[i+2])
						#print wordList[i+2]
						nextLogic = True
					elif word == 'struct' or word == 'union' or word == 'class':
						codeTypes.append(wordList[i+1])
						#print wordList[i+1]
						parent = codeTypes[-1]
						# read the open/close scope  and count the scopes depth until is back to 0, followed by a ';'
						nextLogic = True
						
					else:
						# check for open/close parens after a type,
						# followed by open/close scope and count the scopes depth until is back to 0 
						# check the presence of a * qualifying the type
						
						# for sub-processing the body of a type or function, go back to the indices,
						
						#codeTypes.append(wordList[i+1])
						#print wordList
						wordList[i+1]
						nextLogic = True
						
						# we don't know if we want to handle functions inside structs,
						# one way to avoid it is by not acknowledging the struct type until its scope has ended
			if nextLogic:
				break

	# bad approach, there is no logic that follows new lines in C,
	'''
	lineArray = fileString.split('\n')# to keep track of the line number for creating links later,
	#if False:
	prefix = ''
	for line in lineArray:
		statementArray = line.split(';')
		for statement in statementArray:
			openBracketPos = 
			wordList = statement.split()
			for eType in Types:
				for i, word in enumerate(wordList):
					word = word.strip(' *{}();')
					if word == eType:
						# we need to process inside these as sub-types,
						if word == 'struct' or word == 'union' or word == 'class' or word == 'void':
							if i+1 <= len(wordList)-1:
								typeword = wordList[i+1].strip(' *{}();')
							prefix = typeworld + '.'

						if word == '#define' or word == '#define'
						if word == '#define' or word == '#define'
						print word
						typeword = ''
						if i+1 <= len(wordList)-1:
							typeword = wordList[i+1].strip(' *{}();')
						str = word + ' ' + typeword
						result.append( str )
						if eType == 'typedef':
							User_types.append(typeword)
							Types = sorted( list(set( Default_types + User_types ) ) )
						break
			count += 1
			if count > 1000:
				pprint.pprint(result)
				assert(False)
	'''
#print logicArray
#pprint.pprint(codeTypes)
#pprint.pprint(result)
#pprint.pprint(Types)

fout = open("_tempB.cpp", "w")
#fout.write(outString)
fout.write( pprint.pformat(result) )
#fout.write(fileString)
fout.close()
