import constInfo, chr

#Inauntrul def Refresh(self):
#Inlocuieste:

			if app.ENABLE_SPECULAR_SYSTEM:
				r, g, b, a = shop.GetSpecularColor(i)
				if r == 0 and g == 0 and b == 0:
					r, g, b = 255, 255, 255
				setItemID(i, getItemID(i), itemCount, (1.0, 1.0, 1.0, 1.0), 0, "icon/item/noicon.tga", (float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, 1.0))
			else:
				setItemID(i, getItemID(i), itemCount)
				
				
#Inauntrul, def UnselectItemSlot(self, selectedSlotPos):
#Unde ai "else:", inlocuieste:

			if app.ENABLE_RENDER_TARGET and app.IsPressed(app.DIK_LSHIFT):
				itemIndex = shop.GetItemID(selectedSlotPos)
				self.tooltipItem.ModelPreviewFull(itemIndex)
			else:
				net.SendShopBuyPacket(selectedSlotPos)
				
				
#Inauntrul def OverInItem(self, slotIndex):
#Sub self.tooltipItem.SetShopItem(slotIndex)
#Adauga:

			if app.ENABLE_RENDER_TARGET:
				itemIndex = shop.GetItemID(slotIndex)
				self.tooltipItem.AppendRenderingTooltip(itemIndex)