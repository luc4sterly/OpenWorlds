// 0044bda0 _Java_NET_worlds_scape_PendingCacheDrone_notifySeqLoaded@16 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_PendingCacheDrone_notifySeqLoaded_16
               (int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  char *pcVar1;
  
                    /* 0x4bda0  256  _Java_NET_worlds_scape_PendingCacheDrone_notifySeqLoaded@16 */
  pcVar1 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  FUN_004307f0(param_3,param_1,1,pcVar1);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_4,pcVar1);
  FUN_004304a0(param_3);
  return;
}


