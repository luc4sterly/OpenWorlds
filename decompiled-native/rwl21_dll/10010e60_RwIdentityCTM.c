// 10010e60 RwIdentityCTM [Global]
// programa: RWL21.DLL

bool RwIdentityCTM(void)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x10e60  273  RwIdentityCTM */
  puVar1 = (undefined4 *)FUN_1001d770();
  iVar2 = FUN_1001c4a0(puVar1);
  return (bool)('\x01' - (iVar2 == 0));
}


