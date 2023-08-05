Let's say we are adding a time series demand forecaster component to the code 

Step 1: Architecture & Design
Defining the interface for the demand forecaster and maybe adding uml diagrams to it

#Interface:
itime_series_forecaster.py:

class ITimeSeriesForecaster:
  def train(self, past_data: pd.DataFrame) -> None:

  def predict(self, prediction_period: int) -> float:
    
#Class diagram:

ITimeSeriesForecaster <|-------- ARIMAForcaster

ARIMAForecaster here is an implementation of the interface according to ARIMA time series algorithm


Step 2: Algorithm R&D
Let's say our algorithm is ARIMA. We would have documents specifying exactly how the algorithm works 


Step 3: Interface Tests
Unit tests that should pass for every implementation of the interface 

PR1: description of the tests: you just create a python file with functions of the unit tests you want to write but you don't write
the code you just write the description

itime_series_forecaster_tests.py

class ITimeSeriesForecasterTests:
  def check_input_output_of_train(self):
    '''
    I will pass an argument to train that is not pandas df and I should get an error
    '''

  def check_predict_output(self):
    '''
    I will call predict and see if the output is the correct type
    '''

  def predict_output_is_non_decreasing_with_increase_in_time(self):
    '''
    I am going to predict one period and two period with predict function
    the output of two period should be more than or equal to one period
    '''

PR2: simply coding what we agree on descriptions of the first PR


Step 4: Interface Visual Tests
These are experiments designed to assess the quality of an implementation of the interface. For example, we want to know if ARIMA is good or not. 
Or if Algorithm XYZ we came up with is good or not

PR1: test descriptions
itime_series_forecaster_visual_tests.py

Class ITimeSeriesForecasterVisualTests:
  def assess_performance_on_data_with_trend_and_seasonality():
    '''
    I will create random data of three years according to some trend and month of year seasonality
    I will train the model with two years
    I will compare the output of the model with the last year testing period
    For visualization:
      We create a graph with black line of generated data and green line of prediction in the last year
    '''

  def assess_performance_on_up_to_three_months_prediction():
    '''
    We generate some data
    Get predictions for 1 to 90 days
    Draw the graph of the error for 1 to 90 day predictions 
    '''

PR2: visual reports api: the purpose is that in the test file, we don't want to include any drawing code. We want to separate those drawings 
into another component and create an api for it. The purpose: these api's can later on be used not just for visual tests but also for reports
presentations, etc

You would create folder: for example each file would a function and then we can create a package so that others can import

e.g. 
import itime_series_visual_reports_api as api
api.graph_past_data_and_future_pred(past_data, future_predictions) -> this would then return a fig or draw the graph 
  

PR3: write the code for ITimeSeriesForecasterVisualTests based on the agreed descriptions and the visual reports api we have created 



Step 5: Implementation Unit Test
Now that we want to implement ARIMA forecaster, we write unit test for that implementation 

Step 6: Implementation
Implementing ARIMA forecaster code

Step 7: Consolidating all the tests and making sure everything passes

















