/*
 * stkImageUnitTest.cxx
 *
 *  Created on: 2 Jun 2015
 *      Author: phrfp
 */



#include <iostream>
#include <memory>
#include <vector>
#include "gtest/gtest.h"
#include "stkImageStack.h"
#include "stkImage.h"
#include "stkImageDivision.h"



/**
 * Tests to check that the ImageDivision class is operating correctly
 */

/**
 * Create a set of test images and compute the division
 */


TEST( ImageSum, CheckAdditionOfArray_STL ){

	// 2  4  6  8 => 2x2 image 1

	//Crate simple test image
	std::shared_ptr< std::vector<unsigned short> > testbuffer(new std::vector<unsigned short>( ) );
	unsigned short testValue =2;
	for( int iBuffer = 0; iBuffer < 4; iBuffer++ ){

		testbuffer->push_back(testValue);
		testValue +=2;

	}
	///

	std::shared_ptr<stk::Image<unsigned short> > myImage(new stk::Image<unsigned short>);
	myImage->Initialise( testbuffer, 2, 2 ); //initialise to 2x2 image

	stk::ImageDivision<unsigned short> myDivider;//create divider
	unsigned short divisor=2;
	myDivider.DivideImage( myImage, divisor );//perform the division

	for( std::vector<unsigned short>::iterator it = myImage->StartImage();
			it !=myImage->EndImage(); it++ ){//loop over pixels
		if(it==myImage->StartImage()) EXPECT_EQ( (*it), 1 );//check elements have correct values
		if(it==myImage->StartImage()+1) EXPECT_EQ( (*it), 2 );
		if(it==myImage->StartImage()+2) EXPECT_EQ( (*it), 3 );
		if(it==myImage->StartImage()+3) EXPECT_EQ( (*it), 4 );

	}


}






