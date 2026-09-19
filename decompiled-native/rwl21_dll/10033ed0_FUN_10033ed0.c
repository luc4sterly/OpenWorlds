// 10033ed0 FUN_10033ed0 [Global]
// programa: RWL21.DLL

void __fastcall
FUN_10033ed0(undefined4 param_1,undefined4 param_2,undefined *param_3,undefined *param_4,int param_5
            )

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar7;
  code *pcVar8;
  undefined8 uVar9;
  
  piVar6 = *(int **)(param_5 + 0xa8);
  puVar7 = *(undefined4 **)(param_5 + 0xac);
  uVar1 = *(uint *)(param_5 + 0xa4);
  iVar2 = *piVar6;
  do {
    if (iVar2 == 0) {
      return;
    }
    piVar6 = piVar6 + 1;
    piVar4 = piVar6;
    pcVar8 = (code *)param_4;
    if (uVar1 == 0) {
      pcVar8 = (code *)param_3;
    }
joined_r0x10033f13:
    iVar2 = iVar2 + -1;
    if (-1 < iVar2) {
      puVar3 = (undefined4 *)*puVar7;
      puVar7 = puVar7 + 1;
      uVar9 = FUN_10051000(piVar4,param_2,(int)puVar3);
      uVar5 = -(uint)((int)uVar9 == 0) & 0x10000;
      if (uVar5 != 0) break;
      goto LAB_10033f36;
    }
    uVar1 = (uint)(uVar1 == 0);
    iVar2 = *piVar6;
  } while( true );
  piVar4 = (int *)*puVar3;
  param_2 = CONCAT31((int3)((ulonglong)uVar9 >> 0x28),*(byte *)(piVar4 + 0xc));
  if ((*(byte *)(piVar4 + 0xc) & 0x80) != 0) {
LAB_10033f36:
    (*pcVar8)(puVar3,uVar5);
    piVar4 = extraout_ECX;
    param_2 = extraout_EDX;
  }
  goto joined_r0x10033f13;
}


