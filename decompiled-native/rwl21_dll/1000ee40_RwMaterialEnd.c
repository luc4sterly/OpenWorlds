// 1000ee40 RwMaterialEnd [Global]
// programa: RWL21.DLL

bool RwMaterialEnd(void)

{
  int iVar1;
  
                    /* 0xee40  289  RwMaterialEnd */
  iVar1 = RwPopCurrentMaterial();
  return (bool)('\x01' - (iVar1 == 0));
}


