// 00413870 _Java_NET_worlds_scape_WObject_getJointedObjectToWorldMatrix@12 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_scape_WObject_getJointedObjectToWorldMatrix_12
          (int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
                    /* 0x13870  355  _Java_NET_worlds_scape_WObject_getJointedObjectToWorldMatrix@12
                        */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 == 0) {
    FUN_00402800(s_nWObject_0046f6a4,0x21a);
  }
  uVar2 = FUN_00425380(param_1,param_3);
  FUN_00419420(iVar1,uVar2);
  iVar1 = FUN_00419540(iVar1);
  if (iVar1 != 0) {
    uVar3 = FUN_00419950();
    FUN_004193c0(iVar1,uVar3);
    FUN_00418cb0(uVar2,uVar3);
    FUN_004198f0();
  }
  FUN_004252f0(param_1,param_2,param_3);
  return param_3;
}


