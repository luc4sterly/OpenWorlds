// 00426270 _Java_NET_worlds_scape_Transform_setTransform@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Transform_setTransform_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  
                    /* 0x26270  337  _Java_NET_worlds_scape_Transform_setTransform@12 */
  uVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  uVar2 = (**(code **)(*param_1 + 400))(param_1,param_3,DAT_0049d24c);
  FUN_00418f00(uVar2,uVar1);
  fVar3 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_3,DAT_0049d250);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d250,(float)fVar3);
  fVar3 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_3,DAT_0049d254);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d254,(float)fVar3);
  fVar3 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_3,DAT_0049d258);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d258,(float)fVar3);
  FUN_00412800(param_1,param_2,DAT_0049d25c);
  return;
}


