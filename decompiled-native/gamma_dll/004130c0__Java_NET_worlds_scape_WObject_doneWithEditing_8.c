// 004130c0 _Java_NET_worlds_scape_WObject_doneWithEditing@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_WObject_doneWithEditing_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0x130c0  351  _Java_NET_worlds_scape_WObject_doneWithEditing@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 == 0) {
    FUN_00402800(s_nWObject_0046f6a4,0x10a);
  }
  FUN_00417a90(iVar1);
  return;
}


