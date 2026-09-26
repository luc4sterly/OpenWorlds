// 0040682e FUN_0040682e [Global]
// programa: gdkup.exe

undefined4 __fastcall FUN_0040682e(undefined4 param_1,int param_2)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  (*(code *)PTR_FUN_00408b64)();
  iVar1 = FUN_00406902(1,0x10);
  if (iVar1 != 0) {
    uVar3 = FUN_0040292e();
    puVar2 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
    if ((int)uVar3 == 0) {
      puVar2[2] = param_2;
      puVar2[1] = in_EAX;
      puVar2[3] = (uint)*(byte *)(param_2 + 0x52);
      *puVar2 = DAT_0040b5dc;
      DAT_0040b5dc = puVar2;
    }
    else {
      FUN_00403235();
    }
  }
  (*(code *)PTR_FUN_00408b68)();
  return extraout_ECX;
}


