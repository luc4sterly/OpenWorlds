// 00421cb2 FUN_00421cb2 [Global]
// programa: sfmain.exe

undefined4 __thiscall FUN_00421cb2(void *this,uint *param_1)

{
  undefined4 *pMem;
  int in_EAX;
  HGLOBAL pvVar1;
  undefined4 extraout_ECX;
  int unaff_EBX;
  undefined4 local_10;
  
  pMem = *(undefined4 **)(in_EAX + 0x4e44);
  if (pMem == (undefined4 *)0x0) {
    Ordinal_112(0x2733);
    local_10 = 0xffffffff;
  }
  else {
    *(undefined4 *)(in_EAX + 0x4e44) = *pMem;
    if (*param_1 < 0x10) {
      Ordinal_112(0x271e);
      pvVar1 = GlobalHandle(pMem);
      GlobalUnlock(pvVar1);
      pvVar1 = GlobalHandle(pMem);
      GlobalFree(pvVar1);
      local_10 = 0xffffffff;
    }
    else if (unaff_EBX < (int)pMem[1]) {
      Ordinal_112(0x2733);
      pvVar1 = GlobalHandle(pMem);
      GlobalUnlock(pvVar1);
      pvVar1 = GlobalHandle(pMem);
      GlobalFree(pvVar1);
      local_10 = 0xffffffff;
    }
    else {
      FUN_004080a4(this,(undefined1 *)(pMem + 3));
      *param_1 = 0x10;
      FUN_004080a4(extraout_ECX,(undefined1 *)pMem[7]);
      local_10 = pMem[1];
    }
  }
  return local_10;
}


