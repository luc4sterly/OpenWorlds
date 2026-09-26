// 00402885 FUN_00402885 [Global]
// programa: gdkup.exe

char * __fastcall FUN_00402885(undefined4 param_1,char *param_2)

{
  char cVar1;
  uint in_EAX;
  uint uVar2;
  char *pcVar3;
  uint unaff_EBX;
  char *pcVar4;
  char local_37 [35];
  
  pcVar3 = local_37;
  do {
    uVar2 = in_EAX / unaff_EBX;
    *pcVar3 = "0123456789abcdefghijklmnopqrstuvwxyz"[in_EAX % unaff_EBX];
    pcVar3 = pcVar3 + 1;
    in_EAX = uVar2;
    pcVar4 = param_2;
  } while (uVar2 != 0);
  do {
    pcVar3 = pcVar3 + -1;
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  return param_2;
}


