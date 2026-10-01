// 10004510 FUN_10004510 [Global]
// program: rwdlmd21.dll

void FUN_10004510(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (0 < param_1) {
    do {
      uVar2 = *param_2 & 0x7fffffff;
      uVar1 = DAT_10087054;
      if (uVar2 < 0x3e9) {
        if (uVar2 == 1000) {
          DAT_1008703c = 1;
          goto LAB_100045e6;
        }
        if (uVar2 == 1) {
          *param_2 = *param_2 | 0x80000000;
        }
        else if (uVar2 == 2) {
          DAT_10087068 = param_2[1];
          *param_2 = *param_2 | 0x80000000;
        }
        goto switchD_1000455e_default;
      }
      switch(uVar2) {
      case 0x3ea:
        DAT_1008706c = param_2[1];
        *param_2 = *param_2 | 0x80000000;
        goto switchD_1000455e_default;
      case 0x3eb:
        DAT_10087070 = param_2[1];
        if ((int)DAT_10087070 < 0) {
          DAT_10087070 = 0xffffffff;
        }
        else if (0 < (int)DAT_10087070) {
          DAT_10087070 = 1;
        }
        break;
      case 0x3ec:
        uVar1 = param_2[1];
        if ((uVar1 == 8) || (uVar1 == 0x10)) break;
        goto switchD_1000455e_default;
      case 0x3ed:
        DAT_10087048 = 1;
        break;
      case 0x3ee:
        DAT_10087050 = 1;
        break;
      case 0x3ef:
        DAT_10087040 = 1;
        break;
      default:
        goto switchD_1000455e_default;
      }
LAB_100045e6:
      DAT_10087054 = uVar1;
      *param_2 = *param_2 | 0x80000000;
switchD_1000455e_default:
      param_2 = param_2 + 2;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


