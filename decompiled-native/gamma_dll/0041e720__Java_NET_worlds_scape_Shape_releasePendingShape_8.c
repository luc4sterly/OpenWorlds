// 0041e720 _Java_NET_worlds_scape_Shape_releasePendingShape@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Shape_releasePendingShape_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1e720  296  _Java_NET_worlds_scape_Shape_releasePendingShape@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0048965c);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0048965c,0);
    iVar2 = FUN_00419390(iVar1);
    FUN_004190d0(iVar1);
    if (iVar2 != 0) {
      (**(code **)(*param_1 + 0x58))(param_1,iVar2);
    }
  }
  return;
}


