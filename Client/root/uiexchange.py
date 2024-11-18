import ui, app, grp, time, wndMgr, player, uicommon, exchange, localeInfo, playerSettingModule

#Vezi ce nu ai din astea

#Sub self.OwnerSlot.SetSelectItemSlotEvent(ui.__mem_func__(self.SelectOwnerItemSlot))
#Adauga


		if app.ENABLE_RENDER_TARGET:
			self.OwnerSlot.SetUnselectItemSlotEvent(ui.__mem_func__(self.UnselectItemSlotSelf))
			
			
#Sub self.TargetSlot.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))
#Adauga
		if app.ENABLE_RENDER_TARGET:
			self.TargetSlot.SetUnselectItemSlotEvent(ui.__mem_func__(self.UnselectItemSlotTarget))
			
			
#Inauntrul  def RefreshOwnerSlot(self):
#Inlocuieste asta:

			if app.ENABLE_SPECULAR_SYSTEM:
				r, g, b, a = exchange.GetSpecularColor(i, True)
				if r == 0 and g == 0 and b == 0:
					r, g, b = 255, 255, 255
				self.OwnerSlot.SetItemSlot(i, itemIndex, itemCount, (1.0, 1.0, 1.0, 1.0), 0, "icon/item/noicon.tga", (float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, 1.0))
			else:
				self.OwnerSlot.SetItemSlot(i, itemIndex, itemCount)
				
				
#Inauntrul def RefreshTargetSlot(self):
#Inlocuieste asta:

			if app.ENABLE_SPECULAR_SYSTEM:
				r, g, b, a = exchange.GetSpecularColor(i, False)
				if r == 0 and g == 0 and b == 0:
					r, g, b = 255, 255, 255
				self.TargetSlot.SetItemSlot(i, itemIndex, itemCount, (1.0, 1.0, 1.0, 1.0), 0, "icon/item/noicon.tga", (float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, 1.0))
			else:
				self.TargetSlot.SetItemSlot(i, itemIndex, itemCount)
				
#Dupa functia def Refresh(self):
#Adauga:

	if app.ENABLE_RENDER_TARGET:
		def UnselectItemSlotSelf(self, slotIndex):
			if app.IsPressed(app.DIK_LSHIFT):
				itemVnum =  exchange.GetItemVnumFromSelf(slotIndex)
				self.tooltipItem.ModelPreviewFull(itemVnum, slotIndex)

		def UnselectItemSlotTarget(self, slotIndex):
			if app.IsPressed(app.DIK_LSHIFT):
				itemVnum =  exchange.GetItemVnumFromTarget(slotIndex)
				self.tooltipItem.ModelPreviewFull(itemVnum, slotIndex)
				
#Inauntrul  def OverInOwnerItem(self, slotIndex):
#Adauga:

			if app.ENABLE_RENDER_TARGET:
				itemVnum = exchange.GetItemVnumFromSelf(slotIndex)
				self.tooltipItem.AppendRenderingTooltip(itemVnum)
				
#Inauntrul def OverInTargetItem(self, slotIndex):
#Adauga:

			if app.ENABLE_RENDER_TARGET:
				itemVnum = exchange.GetItemVnumFromTarget(slotIndex)
				self.tooltipItem.AppendRenderingTooltip(itemVnum)