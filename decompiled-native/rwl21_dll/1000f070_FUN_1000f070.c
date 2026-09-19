// 1000f070 FUN_1000f070 [Global]
// programa: RWL21.DLL

bool FUN_1000f070(void)

{
  int iVar1;
  
  iVar1 = RwModelBegin();
  return (bool)('\x01' - (iVar1 == 0));
}


