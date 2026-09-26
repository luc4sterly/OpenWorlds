// 00405788 FUN_00405788 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00405788(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  int in_EAX;
  undefined4 *puVar3;
  undefined4 *extraout_ECX;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  puVar3 = DAT_0040b464;
LAB_004057d5:
  if (puVar3 == (undefined4 *)0x0) {
    return CONCAT44(param_2,iVar5);
  }
  puVar1 = (undefined4 *)*puVar3;
  puVar2 = (undefined *)puVar3[1];
  iVar4 = 1;
  if (((puVar2[0xd] & 0x40) == 0) && ((puVar2[0xd] & 8) == 0)) goto code_r0x004057c0;
  goto LAB_004057cd;
code_r0x004057c0:
  puVar3 = puVar1;
  if (&DAT_00408bc4 + in_EAX * 0x1a <= puVar2) {
    if (puVar2 < &DAT_00408c12) {
      iVar4 = 0;
    }
LAB_004057cd:
    FUN_00402ff0(puVar1,iVar4);
    iVar5 = iVar5 + 1;
    puVar3 = extraout_ECX;
  }
  goto LAB_004057d5;
}


