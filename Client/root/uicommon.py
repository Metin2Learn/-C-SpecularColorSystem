#Adauga la sfarsitul fisierului:

class QuestionDialogWithTimeLimitTHL(QuestionDialog2):

	def __init__(self):
		ui.ScriptWindow.__init__(self)
	
		self.__CreateDialog()
		self.endTime = 0
		self.timeOverMsg = 0
		self.timeOverEvent = None
		self.timeOverEventArgs = None
	
	def __del__(self):
		QuestionDialog2.__del__(self)
	
	def __CreateDialog(self):
		pyScrLoader = ui.PythonScriptLoader()
		pyScrLoader.LoadScriptFile(self, "uiscript/questiondialog2.py")
	
		self.board = self.GetChild("board")
		self.textLine1 = self.GetChild("message1")
		self.textLine2 = self.GetChild("message2")
		self.acceptButton = self.GetChild("accept")
		self.cancelButton = self.GetChild("cancel")

	def Open(self, timeout):
		self.SetCenterPosition()
		self.SetTop()
		self.Show()
		self.endTime = app.GetTime() + timeout	
			
	def SetTimeOverEvent(self, event, *args):
		self.timeOverEvent = event
		self.timeOverEventArgs = args
	
	def SetTimeOverMsg(self, msg):
		self.timeOverMsg = msg
	
	def OnTimeOver(self):
		if self.timeOverEvent:
			apply(self.timeOverEvent, self.timeOverEventArgs)
			self.Hide()
		if self.timeOverMsg:
			chat.AppendChat(chat.CHAT_TYPE_INFO, self.timeOverMsg)		
	
	def OnUpdate(self):
		leftTime = max(0, self.endTime - app.GetTime())
		self.SetText2(localeInfo.UI_LEFT_TIME % (leftTime))	
		if leftTime <= 0:
			self.OnTimeOver()