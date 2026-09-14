// 004553d0 FUN_004553d0 [Global]
// programa: gamma.dll

int __cdecl FUN_004553d0(int param_1,int param_2)

{
  byte bVar1;
  int in_EAX;
  
  if ((param_1 != 0) && ((*(ushort *)(param_1 + 4) >> 7 & 7) != 0)) {
    switch(*(byte *)(param_1 + 5) >> 2 & 3) {
    case 0:
      if (param_2 < 1) {
        if (-1 < param_2) {
          return param_2;
        }
        bVar1 = *(byte *)(param_1 + 5) & 0xf3 | 4;
      }
      else {
        bVar1 = *(byte *)(param_1 + 5) & 0xf3 | 8;
      }
      *(byte *)(param_1 + 5) = bVar1;
      in_EAX = param_2;
      break;
    case 1:
      in_EAX = -1;
      break;
    case 2:
      in_EAX = 1;
    }
    return in_EAX;
  }
  return 0;
}


