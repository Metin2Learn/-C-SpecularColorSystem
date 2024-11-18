import app


#Inauntrul def __ServerCommand_Build(self):
#Adauga

"SaveSpecularColor"				: self.SaveSpecularColor,


#Deasupra def BINARY_ServerCommand_Run(self, line):
#Adauga

		if app.ENABLE_SPECULAR_SYSTEM:
			self.serverCommander.SAFE_RegisterCallBack("SaveSpecularColor", self.SaveSpecularColor)
			
#Deasupra parserWnd = ServerCommandParser()
#Adauga

	def SaveSpecularColor(self, type, name, r, g, b, a):
		pass