# import constInfo daca nu-l ai

#Inlocuieste def SetItemSlot cu

	def SetItemSlot(self, renderingSlotNumber, ItemIndex, ItemCount = 0, diffuseColor = (1.0, 1.0, 1.0, 1.0), id = 0, c_szFileName = "icon/item/noicon.tga", diffuseSpecularColor = (1.0, 1.0, 1.0, 1.0)):


#Adauga la sfarsitul functiei:

		if app.ENABLE_SPECULAR_SYSTEM:
			if constInfo.IsSpecularItem(ItemIndex):
				wndMgr.SetSlotSpecularImage(self.hWnd, renderingSlotNumber, ("d:/ymir work/ui/specular_color_small.tga"), diffuseSpecularColor)
				
				
				
#Sub LIST_BOX_KEY_LIST = ( "width", "height", )
#Adauga

	if app.ENABLE_RENDER_TARGET:
		RENDER_TARGET_KEY_LIST = ( "index", )
		
		
#Deasupra elif Type == "button":
#Adauga

			elif Type == "render_target" and app.ENABLE_RENDER_TARGET:
				parent.Children[Index] = RenderTarget()
				parent.Children[Index].SetParent(parent)
				self.LoadElementRenderTarget(parent.Children[Index], ElementValue, parent)
				
				
#Deasupra def LoadElementTitleBar(self, window, value, parentWindow):
#Adauga

	if app.ENABLE_RENDER_TARGET:
		def LoadElementRenderTarget(self, window, value, parentWindow):
	
			if False == self.CheckKeyList(value["name"], value, self.RENDER_TARGET_KEY_LIST):
				return False
	
			window.SetSize(value["width"], value["height"])
			
			if True == value.has_key("style"):
				for style in value["style"]:
					window.AddFlag(style)
					
			self.LoadDefaultData(window, value, parentWindow)
			
			if value.has_key("index"):
				window.SetRenderTarget(int(value["index"]))
	
			return True
			
#Sub RegisterToolTipWindow("TEXT", TextLine)
#Adauga:

class RenderTarget(Window):

	def __init__(self, layer = "UI"):
		Window.__init__(self, layer)
		
		self.number = -1

	def __del__(self):
		Window.__del__(self)

	def RegisterWindow(self, layer):
		self.hWnd = wndMgr.RegisterRenderTarget(self, layer)
		
	def SetRenderTarget(self, number):
		self.number = number
		wndMgr.SetRenderTarget(self.hWnd, self.number)