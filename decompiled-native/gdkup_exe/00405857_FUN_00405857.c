// 00405857 FUN_00405857 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00405857(undefined4 param_1,undefined4 param_2)

{
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  
  (*(code *)PTR_FUN_00408b4c)(param_2,param_1);
  iVar3 = 0;
  uVar1 = extraout_ECX;
  for (puVar2 = DAT_0040b464; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if (((*(uint *)(puVar2[1] + 0xc) & uVar1) != 0) &&
       (iVar3 = iVar3 + 1, (*(byte *)(puVar2[1] + 0xd) & 0x10) != 0)) {
      uVar4 = FUN_00403e5d(uVar1,puVar2);
      puVar2 = (undefined4 *)((ulonglong)uVar4 >> 0x20);
      uVar1 = extraout_ECX_00;
    }
  }
  (*(code *)PTR_FUN_00408b50)();
  return CONCAT44(param_2,iVar3);
}


