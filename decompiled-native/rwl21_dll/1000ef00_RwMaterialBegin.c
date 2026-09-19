// 1000ef00 RwMaterialBegin [Global]
// programa: RWL21.DLL

bool RwMaterialBegin(void)

{
  int iVar1;
  
                    /* 0xef00  288  RwMaterialBegin */
  iVar1 = RwPushCurrentMaterial();
  return (bool)('\x01' - (iVar1 == 0));
}


