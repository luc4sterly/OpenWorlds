// 00450e10 FUN_00450e10 [Global]
// programa: gamma.dll

ushort __cdecl FUN_00450e10(int *param_1)

{
  ushort *puVar1;
  
  do {
    puVar1 = (ushort *)param_1[2];
    if ((puVar1 != (ushort *)0x0) && ((*puVar1 & 0x8000) == 0)) {
      switch(*puVar1) {
      case 1:
        param_1[2] = param_1[2] + 10;
        break;
      case 2:
        param_1[2] = param_1[2] + 0xe;
        break;
      default:
        FUN_00458ca0();
        break;
      case 4:
        param_1[2] = param_1[2] + 10;
        break;
      case 5:
        param_1[2] = param_1[2] + 0x12;
        break;
      case 6:
        param_1[2] = param_1[2] + 0x12;
        break;
      case 7:
      case 0xc:
        param_1[2] = param_1[2] + 0xe;
        break;
      case 8:
        param_1[2] = param_1[2] + 0x12;
        break;
      case 9:
        param_1[2] = param_1[2] + 0x16;
        break;
      case 10:
        param_1[2] = param_1[2] + 10;
        break;
      case 0xb:
        param_1[2] = param_1[2] + 0xe;
        break;
      case 0x10:
        param_1[2] = param_1[2] + 0xe;
        break;
      case 0x11:
        param_1[2] = param_1[2] + 6;
        break;
      case 0x13:
        param_1[2] = param_1[2] + (uint)puVar1[1] * 4 + 0xc;
      }
      break;
    }
    FUN_00450c70(*(char **)(param_1[3] + 4),param_1);
    if (*param_1 == 0) {
      FUN_00458ca0();
    }
    param_1[4] = param_1[3];
    param_1[3] = *(int *)param_1[3];
  } while (param_1[2] == 0);
  return *(ushort *)param_1[2] & 0xff;
}


