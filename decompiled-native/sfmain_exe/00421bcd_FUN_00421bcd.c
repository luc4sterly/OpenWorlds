// 00421bcd FUN_00421bcd [Global]
// programa: sfmain.exe

int __fastcall FUN_00421bcd(undefined1 *param_1,undefined1 *param_2)

{
  int in_EAX;
  HGLOBAL hMem;
  undefined4 *puVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_EBX;
  int local_10;
  
  hMem = GlobalAlloc(0x40,unaff_EBX + 0x20);
  puVar1 = GlobalLock(hMem);
  if (puVar1 == (undefined4 *)0x0) {
    Ordinal_112(0x2747);
    local_10 = -1;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = unaff_EBX;
    puVar1[2] = DAT_004627ac;
    FUN_004080a4(extraout_ECX,param_1);
    FUN_004080a4(extraout_ECX_00,param_2);
    local_10 = unaff_EBX;
    if (*(int *)(in_EAX + 0x4e44) == 0) {
      *(undefined4 **)(in_EAX + 0x4e48) = puVar1;
      *(undefined4 *)(in_EAX + 0x4e44) = *(undefined4 *)(in_EAX + 0x4e48);
    }
    else {
      **(undefined4 **)(in_EAX + 0x4e48) = puVar1;
      *(undefined4 **)(in_EAX + 0x4e48) = puVar1;
    }
  }
  return local_10;
}


