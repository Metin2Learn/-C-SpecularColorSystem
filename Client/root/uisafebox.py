#Inauntrul def RefreshSafebox(self):
#Inlocuieste:

			if app.ENABLE_SPECULAR_SYSTEM:
				r, g, b, a = safebox.GetSpecularColor(slotIndex)
				if r == 0 and g == 0 and b == 0:
					r, g, b = 255, 255, 255
				setItemID(i, getItemID(slotIndex), itemCount, (1.0, 1.0, 1.0, 1.0), 0, "icon/item/noicon.tga", (float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, 1.0))
			else:
				setItemID(i, getItemID(slotIndex), itemCount)
				
#Cauta:mouseModule.mouseController.AttachObject(self, player.SLOT_TYPE_SAFEBOX, selectedSlotPos, selectedItemID)

#Sub, ai:
def UseItemSlot(self, slotIndex):

#Inauntru, adauga:

		if app.ENABLE_RENDER_TARGET:
			if app.IsPressed(app.DIK_LSHIFT):
				itemVnum = safebox.GetItemID(slotIndex)
				self.tooltipItem.ModelPreviewFull(itemVnum, slotIndex)
				
#Mai jos, ai:
def __ShowToolTip(self, slotIndex):

#Inauntru, adauga:

			if app.ENABLE_RENDER_TARGET:
				itemVnum = safebox.GetItemID(slotIndex)
				self.tooltipItem.AppendRenderingTooltip(itemVnum)
				

#Cauta def RefreshMall(self):
#Inauntru, inlocuieste:

			if app.ENABLE_SPECULAR_SYSTEM:
				r, g, b, a = safebox.GetMallSpecularColor(i)
				if r == 0 and g == 0 and b == 0:
					r, g, b = 255, 255, 255
				setItemID(i, itemID, itemCount, (1.0, 1.0, 1.0, 1.0), 0, "icon/item/noicon.tga", (float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, 1.0))
			else:
				setItemID(i, itemID, itemCount)
				
				
#Mai jos, cauta mouseModule.mouseController.AttachObject(self, player.SLOT_TYPE_MALL, selectedSlotPos, selectedItemID)

#Sub, ai
def UseItemSlot(self, slotIndex):
#Inauntru, adauga:

		if app.ENABLE_RENDER_TARGET:
			if app.IsPressed(app.DIK_LSHIFT):
				itemVnum = safebox.GetMallItemID(slotIndex)
				self.tooltipItem.ModelPreviewFull(itemVnum, slotIndex)
				
#Sub, ai: 
def __ShowToolTip(self, slotIndex):

#Inauntru, adauga:

			if app.ENABLE_RENDER_TARGET:
				itemVnum = safebox.GetMallItemID(slotIndex)
				self.tooltipItem.AppendRenderingTooltip(itemVnum)