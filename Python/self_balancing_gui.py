from dash import Dash, html, dcc
import dash_daq as daq
import plotly.graph_objs as go

# Initialize the Dash app
app = Dash(__name__)

# Sample data for the graphs
time_data = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
pitch_data = [0, 1, 2, 3, 2, 1, 0, -1, -2, -3]
control_right_data = [0, 0.5, 1, 0.8, 0.6, 0.4, 0.3, 0.1, 0, -0.2]
control_left_data = [0, -0.5, -1, -0.8, -0.6, -0.4, -0.3, -0.1, 0, 0.2]
battery_data = [100, 98, 97, 95, 94, 92, 91, 90, 89, 88]

# Layout
app.layout = html.Div([
    html.Div(className='app-header', children=[
        html.H1("Self-Balancing Robot GUI", className='title')
    ], style={'textAlign': 'center', 'marginBottom': '20px'}),

    html.Div([
        html.Div([
            html.Div([
                dcc.Graph(
                    id='pitch_graph',
                    figure={
                        'data': [go.Scatter(x=time_data, y=pitch_data, mode='lines+markers', name='Pitch')],
                        'layout': go.Layout(title='Pitch vs Time', xaxis={'title': 'Time [s]'}, yaxis={'title': 'Pitch [deg]'})
                    }
                )
            ], style={'width': '48%', 'display': 'inline-block', 'verticalAlign': 'top'}),

            html.Div([
                dcc.Graph(
                    id='battery_graph',
                    figure={
                        'data': [go.Scatter(x=time_data, y=battery_data, mode='lines+markers', name='Battery')],
                        'layout': go.Layout(title='Battery vs Time', xaxis={'title': 'Time [s]'}, yaxis={'title': 'Battery [%]'})
                    }
                )
            ], style={'width': '48%', 'display': 'inline-block', 'verticalAlign': 'top'}),

            html.Div([
                dcc.Graph(
                    id='control_action_right_graph',
                    figure={
                        'data': [go.Scatter(x=time_data, y=control_right_data, mode='lines+markers', name='Control Right')],
                        'layout': go.Layout(title='Control Action Right', xaxis={'title': 'Time [s]'}, yaxis={'title': 'PWM'})
                    }
                )
            ], style={'width': '48%', 'display': 'inline-block', 'verticalAlign': 'top'}),

            html.Div([
                dcc.Graph(
                    id='control_action_left_graph',
                    figure={
                        'data': [go.Scatter(x=time_data, y=control_left_data, mode='lines+markers', name='Control Left')],
                        'layout': go.Layout(title='Control Action Left', xaxis={'title': 'Time [s]'}, yaxis={'title': 'PWM'})
                    }
                )
            ], style={'width': '48%', 'display': 'inline-block', 'verticalAlign': 'top'})
        ], style={'flex': 1, 'padding': '20px'})
    ], style={'display': 'flex', 'width': '100%'})
])

if __name__ == '__main__':
    app.run(debug=True)
