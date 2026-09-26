// 00405aa0 FUN_00405aa0 [Global]
// programa: gdkup.exe

void __fastcall FUN_00405aa0(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *extraout_ECX;
  undefined4 unaff_EBX;
  
  *(undefined4 *)(in_EAX + 4) = param_2;
  *(undefined4 *)(in_EAX + 8) = unaff_EBX;
  iVar1 = (*(code *)PTR_FUN_00408b38)(param_1);
  puVar2 = (undefined4 *)(iVar1 + DAT_0040b440);
  *extraout_ECX = *puVar2;
  *puVar2 = extraout_ECX;
  return;
}


