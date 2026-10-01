// 0040253a FUN_0040253a [Global]
// program: run.exe

void __cdecl FUN_0040253a(undefined *param_1)

{
  undefined *lpMem;
  uint *puVar1;
  byte *pbVar2;
  int local_8;
  
  lpMem = param_1;
  if (param_1 != (undefined *)0x0) {
    if (DAT_0040ce64 == 3) {
      puVar1 = (uint *)FUN_00403c11((int)param_1);
      if (puVar1 != (uint *)0x0) {
        FUN_00403c3c(puVar1,(int)lpMem);
        return;
      }
    }
    else if ((DAT_0040ce64 == 2) &&
            (pbVar2 = (byte *)FUN_0040496c(param_1,&local_8,(uint *)&param_1), pbVar2 != (byte *)0x0
            )) {
      FUN_004049c3(local_8,(int)param_1,pbVar2);
      return;
    }
    HeapFree(DAT_0040ce60,0,lpMem);
  }
  return;
}


