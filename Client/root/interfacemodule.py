if app.ENABLE_RENDER_TARGET:
	import uiRenderTarget
if app.ENABLE_SPECULAR_SYSTEM:
	import uiSpecularColor
	if app.ENABLE_EFFECT_COLOR_SYSTEM:
		import uiEffectColor
		
#Sub self.wndGuildBuilding = None
#Adauga

		if app.ENABLE_RENDER_TARGET:
			self.wndTargetRender = None
		if app.ENABLE_SPECULAR_SYSTEM:
			self.wndSpecularColor = None
			if app.ENABLE_EFFECT_COLOR_SYSTEM:
				self.wndEffectColor = None
				
				
#Sub self.wndChatLog = wndChatLog
#Adauga 

		if app.ENABLE_RENDER_TARGET:
			self.wndTargetRender = uiRenderTarget.RenderTarget.Get()
			self.wndTargetRender.BindInterface(self)
			self.wndTargetRender.Hide()
		if app.ENABLE_SPECULAR_SYSTEM:
			self.wndSpecularColor = uiSpecularColor.SpecularColor()
			if app.ENABLE_EFFECT_COLOR_SYSTEM:
				self.wndEffectColor = uiEffectColor.EffectColor()
				
#Sub self.tooltipItem = uiToolTip.ItemToolTip()
#Adauga:

self.tooltipItem.BindInterface(self)


#Sub del self.wndItemSelect
#Adauga:

		if app.ENABLE_RENDER_TARGET:
			if self.wndTargetRender:
				self.wndTargetRender.Hide()
				self.wndTargetRender.Destroy()
				del self.wndTargetRender
		if app.ENABLE_SPECULAR_SYSTEM:
			if self.wndSpecularColor:
				self.wndSpecularColor.Hide()
				self.wndSpecularColor.Destroy()
				del self.wndSpecularColor
			if app.ENABLE_EFFECT_COLOR_SYSTEM:
				if self.wndEffectColor:
					self.wndEffectColor.Hide()
					self.wndEffectColor.Destroy()
					del self.wndEffectColor
					
					
#Sub self.wndExpandedTaskBar.Hide()
#Adauga:

		if app.ENABLE_RENDER_TARGET:
			if self.wndTargetRender:
				self.wndTargetRender.Hide()
					 
		if app.ENABLE_SPECULAR_SYSTEM:
			if self.wndSpecularColor:
				self.wndSpecularColor.Hide()
				
			if app.ENABLE_EFFECT_COLOR_SYSTEM:
				if self.wndEffectColor:
					self.wndEffectColor.Hide()
					
					
					
#Deasupra def __HideWindows(self):
#Adauga


	if app.ENABLE_SPECULAR_SYSTEM:
		def OpenSpecularColorBoard(self, itemVnum, slotIndex, isEquip):
			if self.wndSpecularColor:
				self.wndSpecularColor.Open(itemVnum, slotIndex, isEquip)
				self.wndSpecularColor.SetCenterPosition()
		
		if app.ENABLE_EFFECT_COLOR_SYSTEM:
			def OpenEffectColorBoard(self, itemVnum, slotIndex, isEquip):
				if self.wndEffectColor:
					self.wndEffectColor.Open(itemVnum, slotIndex, isEquip)
					self.wndEffectColor.SetCenterPosition()



#Deasupra hideWindows = filter(lambda x:x.IsShow(), hideWindows)
#Adauga:

		if app.ENABLE_RENDER_TARGET:
			if self.wndTargetRender:
				hideWindows += self.wndTargetRender,
		if app.ENABLE_SPECULAR_SYSTEM:
			if self.wndSpecularColor:
				hideWindows += self.wndSpecularColor,
			
			if app.ENABLE_EFFECT_COLOR_SYSTEM:
				if self.wndEffectColor:
					hideWindows += self.wndEffectColor,