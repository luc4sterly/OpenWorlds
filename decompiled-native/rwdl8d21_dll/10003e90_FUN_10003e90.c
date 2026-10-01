// 10003e90 FUN_10003e90 [Global]
// program: RWDL8D21.DLL

void FUN_10003e90(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (0 < param_1) {
    do {
      uVar2 = *param_2 & 0x7fffffff;
      uVar1 = DAT_10075054;
      if (uVar2 < 0x3e9) {
        if (uVar2 == 1000) {
          DAT_1007503c = 1;
          goto LAB_10003f66;
        }
        if (uVar2 == 1) {
          *param_2 = *param_2 | 0x80000000;
        }
        else if (uVar2 == 2) {
          DAT_10075068 = param_2[1];
          *param_2 = *param_2 | 0x80000000;
        }
        goto switchD_10003ede_default;
      }
      switch(uVar2) {
      case 0x3ea:
        DAT_1007506c = param_2[1];
        *param_2 = *param_2 | 0x80000000;
        goto switchD_10003ede_default;
      case 0x3eb:
        DAT_10075070 = param_2[1];
        if ((int)DAT_10075070 < 0) {
          DAT_10075070 = 0xffffffff;
        }
        else if (0 < (int)DAT_10075070) {
          DAT_10075070 = 1;
        }
        break;
      case 0x3ec:
        uVar1 = param_2[1];
        if ((uVar1 == 8) || (uVar1 == 0x10)) break;
        goto switchD_10003ede_default;
      case 0x3ed:
        DAT_10075048 = 1;
        break;
      case 0x3ee:
        DAT_10075050 = 1;
        break;
      case 0x3ef:
        DAT_10075040 = 1;
        break;
      default:
        goto switchD_10003ede_default;
      }
LAB_10003f66:
      DAT_10075054 = uVar1;
      *param_2 = *param_2 | 0x80000000;
switchD_10003ede_default:
      param_2 = param_2 + 2;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


