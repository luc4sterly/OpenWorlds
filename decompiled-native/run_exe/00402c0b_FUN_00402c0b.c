// 00402c0b FUN_00402c0b [Global]
// programa: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402c0b(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_0040cf88 == 0) {
    FUN_00405bd5();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_0040ba88,0x104);
  _DAT_0040ba70 = &DAT_0040ba88;
  pbVar2 = &DAT_0040ba88;
  if (*DAT_0040cf98 != 0) {
    pbVar2 = DAT_0040cf98;
  }
  FUN_00402ca4(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_00402ca4(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_0040ba58 = puVar1;
  _DAT_0040ba54 = local_8 + -1;
  return;
}


