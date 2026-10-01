// 004148f0 FUN_004148f0 [Global]
// program: gamma.dll

void __cdecl FUN_004148f0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  float10 fVar5;
  float10 fVar6;
  int *piVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  longlong lVar10;
  undefined4 local_1c [3];
  
  fVar5 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_3,DAT_0049fe14);
  fVar6 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_3,DAT_0049ff30);
  iVar1 = FUN_00418250(param_2,param_4,(int)ROUND((float)fVar5),(int)ROUND((float)fVar6),local_1c);
  if (iVar1 != 0) {
    iVar1 = FUN_004147a0(iVar1);
    if (iVar1 == 0) {
      (**(code **)(*param_1 + 0x1a0))(param_1,param_3,DAT_00489488,0);
      (**(code **)(*param_1 + 0x1a0))(param_1,param_3,DAT_0048947c,0);
    }
    else {
      iVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Point3Temp_0046fcd4);
      if (iVar2 == 0) {
        FUN_00402800(s_nCamera_0046fbd0,0x11e);
      }
      iVar3 = FUN_004031c0(param_1,iVar2,&DAT_0046fd14,s__FFF_LNET_worlds_scape_Point3Tem_0046fcf0);
      if (iVar3 == 0) {
        FUN_00402800(s_nCamera_0046fbd0,0x122);
      }
      uVar4 = FUN_00403f80(param_1,iVar2,iVar3);
      piVar7 = param_1;
      iVar2 = (**(code **)(*param_1 + 0x3c))();
      if (iVar2 == 0) {
        uVar9 = CONCAT44(piVar7,iVar1);
        uVar8 = CONCAT44(DAT_00489488,param_3);
        piVar7 = param_1;
        (**(code **)(*param_1 + 0x1a0))();
        (**(code **)(*param_1 + 0x1a0))(param_1,param_3,DAT_0048947c,uVar4,piVar7,uVar8,uVar9);
      }
      else {
        lVar10 = ZEXT48(piVar7) << 0x20;
        uVar8 = CONCAT44(DAT_00489488,param_3);
        piVar7 = param_1;
        (**(code **)(*param_1 + 0x1a0))();
        (**(code **)(*param_1 + 0x1a0))(param_1,param_3,DAT_0048947c,0,piVar7,uVar8,lVar10);
      }
    }
  }
  return;
}


