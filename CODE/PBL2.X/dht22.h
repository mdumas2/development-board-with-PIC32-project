/* 
 * File:   dht22.h
 * Author: GUILH
 *
 * Created on October 11, 2019, 6:18 PM
 */

#ifndef DHT22_H
#define	DHT22_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
void start_signal(void);
short check_response(void);
unsigned int Read_Data(void);
void principal(void);
#endif	/* DHT22_H */

