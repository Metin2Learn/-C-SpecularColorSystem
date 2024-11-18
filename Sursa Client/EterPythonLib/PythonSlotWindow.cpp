// Inauntrul CSlotWindow::AppendSlot
// Dupa TSlot Slot;
// Adauga 

#ifdef ENABLE_SPECULAR_SYSTEM
	Slot.pInstanceSpecular = NULL;
#endif


// Deasupra void CSlotWindow::SetSlotCount(DWORD dwIndex, DWORD dwCount)
// Adauga

#ifdef ENABLE_SPECULAR_SYSTEM
void CSlotWindow::SetSlotSpecularImage(DWORD dwIndex, CGraphicImage* specularImage, D3DXCOLOR& diffuseColor)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwIndex, &pSlot) || !specularImage)
		return;
	assert(NULL == pSlot->pInstanceSpecular);
	pSlot->pInstanceSpecular = CGraphicImageInstance::New();
	pSlot->pInstanceSpecular->SetDiffuseColor(diffuseColor.r, diffuseColor.g, diffuseColor.b, diffuseColor.a);
	pSlot->pInstanceSpecular->SetImagePointer(specularImage);
}
#endif

// Inauntrul void CSlotWindow::ClearSlot(TSlot * pSlot)
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	if (pSlot->pInstanceSpecular)
	{
		CGraphicImageInstance::Delete(pSlot->pInstanceSpecular);
		pSlot->pInstanceSpecular = NULL;
	}
#endif

// Sub if (rSlot.pFinishCoolTimeEffect)
// Adauga:


#ifdef ENABLE_SPECULAR_SYSTEM
		if (rSlot.pInstanceSpecular)
		{
			int slotsize = rSlot.byyPlacedItemSize;
			rSlot.pInstanceSpecular->SetPosition(m_rect.left + rSlot.ixPosition + 19, (m_rect.top + rSlot.iyPosition));
			rSlot.pInstanceSpecular->Render();
		}
#endif