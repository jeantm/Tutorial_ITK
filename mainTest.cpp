#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkBinaryThresholdImageFilter.h"


typedef unsigned char InputPixelType;
typedef unsigned char OutputPixelType;
const unsigned int Dimension = 2;

typedef itk::Image< InputPixelType, Dimension > InputImageType;
typedef itk::Image< OutputPixelType, Dimemsion > OutputImageType;

typedef itk::BinaryThresholdImageFilter< InputImageType, OutputImageType > FilterType;

typedef itk::ImageFileReader< IntputImageType > ReaderType;
typedef itk::ImageFileWriter< OutputImageType > WriterType;

ReaderType::Pointer reader = ReaderType::New();
WriterType::Pointer writer = WriterType::New();
FilterType::Pointer filter = FilterType::New();

reader->SetFileName( argv[1] );
writer->SetFileName( argv[2] );

filter->SetInput( reader->GetOutput() );

filter->SetOutsideValue( outsideValue );
filter->SetInsideValue( insideValue );

filter->SetLowerThreshold( lowerTreshold );
filter->SetUpperThreshold( upperTreshold );

filter->Update();
