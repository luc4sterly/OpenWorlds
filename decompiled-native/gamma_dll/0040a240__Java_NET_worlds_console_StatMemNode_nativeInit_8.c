// 0040a240 _Java_NET_worlds_console_StatMemNode_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_StatMemNode_nativeInit_8(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* 0xa240  71  _Java_NET_worlds_console_StatMemNode_nativeInit@8 */
  if (DAT_004890d0 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_console_StatMemNode_0046e000);
    DAT_004890d0 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_004890d0 == 0) {
      FUN_00402800(s_nStatMemNode_0046e020,0x24);
    }
    DAT_004890d4 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004890d0,s__totPhysMem_0046e034,&DAT_0046e030);
    DAT_004890d8 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004890d0,s__availPhysMem_0046e040,&DAT_0046e030);
    DAT_004890dc = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004890d0,s__totPageMem_0046e050,&DAT_0046e030);
    DAT_004890e0 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004890d0,s__availPageMem_0046e05c,&DAT_0046e030);
    bVar1 = false;
    if ((DAT_004890d4 != 0) && (DAT_004890d8 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nStatMemNode_0046e020,0x2e);
    }
    bVar1 = false;
    if ((DAT_004890dc != 0) && (DAT_004890e0 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nStatMemNode_0046e020,0x2f);
    }
  }
  return;
}


